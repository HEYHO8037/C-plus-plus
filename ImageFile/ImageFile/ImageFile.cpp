#include <iostream>

using namespace std;
static int ImageFileByte = 6556414;

int main(void)
{
	// 2. 이미지 파일을 파일 입출력을 통해서 똑같이 저장 하시오.(바이너리) - 색상은 1바이트 짜리 자료형, 전체파일의 크기만큼  불러들이면 됨.
	FILE* pGetFile = nullptr;
	FILE* pSetFile = nullptr;

	char saveImage;

	errno_t err2 = fopen_s(&pSetFile, "../Data/saveImage.jpg", "ab");
	errno_t err = fopen_s(&pGetFile, "../Data/Image.jpg", "rb");

	if (NULL == err && NULL == err2)
	{
		for (int i = 0; i < ImageFileByte; ++i)
		{
			fread(&saveImage, sizeof(char), 1, pGetFile);
			fwrite(&saveImage, sizeof(char), 1, pSetFile);
		}

		cout << "성공! 폴더를 확인하세요" << endl;
	}
	else
	{
		cout << "실패" << endl;
	}

	fclose(pGetFile);
	fclose(pSetFile);

	return 0;
}