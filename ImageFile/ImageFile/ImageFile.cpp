#include <iostream>

using namespace std;
static int ImageFileByte = 6556414;

int main(void)
{
	// 2. �̹��� ������ ���� ������� ���ؼ� �Ȱ��� ���� �Ͻÿ�.(���̳ʸ�) - ������ 1����Ʈ ¥�� �ڷ���, ��ü������ ũ�⸸ŭ  �ҷ����̸� ��.
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

		cout << "����! ������ Ȯ���ϼ���" << endl;
	}
	else
	{
		cout << "����" << endl;
	}

	fclose(pGetFile);
	fclose(pSetFile);

	return 0;
}