#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

const int size = 3;
typedef float Matrix[size][size];

struct Args
{
	std::string firstMatrixFileName;
	std::string secondMatrixFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count.\n";
		std::cout << "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
		return std::nullopt;
	}
	Args args;
	args.firstMatrixFileName = argv[1];
	args.secondMatrixFileName = argv[2];
	return args;
}

int OpenFile(std::ifstream& file, std::string path)
{
	file.open(path);
	if (!file)
	{
		std::cout << "Failed to open '" << path << "' for reading\n";
		return 0;
	}
	return 1;
}

int LoadMatrixLine(const std::string& line, Matrix& matrix, int matrixLineIndex, int countElements)
{
	std::stringstream lineStream(line);
	float element;
	int elementIndex = 0;
	while (lineStream >> element)
	{
		matrix[matrixLineIndex][elementIndex] = element;
		elementIndex++;
	}
	if (elementIndex != countElements)
	{
		return 0;
	}
	return 1;
}

int LoadMatrixFromFile(std::ifstream& file, Matrix& matrix)
{
	std::string line;
	int lineIndex = 0, errorCode = 1;
	while (std::getline(file, line))
	{
		if (LoadMatrixLine(line, matrix, lineIndex, size) != 1)
		{
			errorCode = 0;
			break;
		}
		lineIndex++;
	}
	if (lineIndex != size)
	{
		errorCode = 0;
	}
	if (errorCode == 0)
	{
		std::cout << "Invalid matrix.\n";
		std::cout << "Matrix must be quadratic 3x3\n";
		return errorCode;
	}
	return errorCode;
}

void PrintMatrix(const Matrix& matrix)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j != 0)
			{
				std::cout << "\t";
			}
			printf("%.3f", matrix[i][j]);
		}
		std::cout << "\n";
	}
}

void MultiplicationMatrixs(const Matrix& matrix1, const Matrix& matrix2, Matrix& multMatrix)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			float element = 0;
			for (int k = 0; k < size; k++)
			{
				element += matrix1[i][k] * matrix2[k][j];
			}
			multMatrix[i][j] = element;
		}
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	std::ifstream inputMatrix1, inputMatrix2;
	if (OpenFile(inputMatrix1, args->firstMatrixFileName) != 1)
	{
		return 1;
	}
	if (OpenFile(inputMatrix2, args->secondMatrixFileName) != 1)
	{
		return 1;
	}

	Matrix matrix1, matrix2;
	if (LoadMatrixFromFile(inputMatrix1, matrix1) != 1)
	{
		return 1;
	}
	if (LoadMatrixFromFile(inputMatrix2, matrix2) != 1)
	{
		return 1;
	}

	Matrix multMatrix;
	MultiplicationMatrixs(matrix1, matrix2, multMatrix);
	PrintMatrix(multMatrix);

	return 0;
}
