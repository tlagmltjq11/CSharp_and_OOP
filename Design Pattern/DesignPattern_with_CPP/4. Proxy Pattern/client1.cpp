#include <iostream>
#include "ecourse_dp.hpp"
using namespace std;
using namespace ecourse;

// Section4. �������� ����
// Proxy

// Proxy Patter : � ��ü�� ���� ������ �����ϱ� ���� �뵵��
// "�븮���̳� �뺯�ο� �ش��ϴ� ��ü�� �����ϴ� ����"

// �ٽ�
// 1. �� �ڵ带 ������ ��� �����ϸ� ���Ͻ� ������ �˾ƺ� ����.

int main()
{
	int server = ec_find_server("CalcService");

	cout << "server : " << server << endl;

	int ret = ec_send_server(server, 1, 10, 20);

	cout << ret << endl; // 30
}
