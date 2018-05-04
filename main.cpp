#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

const int FILENAME_MAXLEN = 256;
const int LINE_MAXLEN = 256;

int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cout << "usage: \n";
		std::cout << "\t my_diff src1 src2 \n";
		return 1;
	}

	std::ifstream src1(argv[1]);
	std::ifstream src2(argv[2]);

	char diff_filename[FILENAME_MAXLEN] = "diff-";
	strcat(diff_filename, argv[1]);
	strcat(diff_filename, "-");
	strcat(diff_filename, argv[2]);
	std::ofstream diff(diff_filename);

	char buffer1[LINE_MAXLEN], buffer2[LINE_MAXLEN];

	while ( !src1.eof() && !src2.eof() ) {
		src1.getline(buffer1, LINE_MAXLEN);
		src2.getline(buffer2, LINE_MAXLEN);
		if (strcmp(buffer1, buffer2) == 0)
			diff << " " << buffer1 << std::endl;
		else {
			diff << "-" << buffer1 << std::endl;
			diff << "+" << buffer2 << std::endl;
		}
	}

	src1.close();
	src2.close();
	diff.close();

	return 0;
}