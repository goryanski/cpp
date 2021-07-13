#include "AdminLoginHelper.h"

AdminLoginHelper::AdminLoginHelper()
{
	utils = Utils::getInstance();
	encryptionKey = "abc";
}

void AdminLoginHelper::saveAdminAccount(Account admin)
{
	accountValidation(admin);

	// ������������� ����� � ������
	string encryptedLogin = xor_crypt(encryptionKey, admin.getLogin());
	string encryptedPassword = xor_crypt(encryptionKey, admin.getPassword());

	//�������� ����� �� ������
	ofstream os(utils->ADMIN_PATH, ios::in | ios::binary | ios::trunc);
	if (os.is_open()) {
		os << encryptedLogin << endl;
		os << encryptedPassword << endl;
		os.close();
	}
}

string AdminLoginHelper::readAdminLogin()
{
	string login;

	ifstream is(utils->ADMIN_PATH, ios::out | ios::binary);
	if (is.is_open()) {		
		getline(is, login, '\n');
		is.close();
	}

	// ��������������
	string decryptedLogin = decryptionString(login);
	return decryptedLogin;

	// ���������� ������������� ������� ���� �� �����, �.�. ���� ��� ����� ������,
	// �� ���� ��� ����� �� �������, �� ������� ���� ��������� ��� ������ ������� ���������
}

bool AdminLoginHelper::isPasswordValid(string password)
{
	ifstream is(utils->ADMIN_PATH, ios::out | ios::binary);
	if (is.is_open()) {
		string passwordExist;
		// ��� ������ ���������� � ���������� passwordExist ������� ����� � ��� ������ - ������
		getline(is, passwordExist, '\n');
		getline(is, passwordExist, '\n');
		is.close();

		// �������������� ������
		string decryptedPassword = decryptionString(passwordExist);

		if (decryptedPassword == password) {
			return true;
		}
		else {
			throw IncorrectPasswordException("Incorrect admin password");
		}
	}
}

void AdminLoginHelper::accountValidation(Account admin)
{
	if (admin.getLogin().length() < 4 || admin.getLogin().length() > 15) {
		throw IncorrectRegistrationInfoException("Login must be 4-15 symbols");
	}
	if (admin.getPassword().length() < 5 || admin.getPassword().length() > 16) {
		throw IncorrectRegistrationInfoException("Password must be 5-16 symbols");
	}
}

string AdminLoginHelper::xor_crypt(const string key, string str)
{
	string data = str;
	int pos = 0;
	for (size_t i = 0; i < data.size(); i++) {
		data[i] ^= key[pos++];
		if (pos == key.size()) pos = 0;
	}
	return data;
}

string AdminLoginHelper::decryptionString(string str)
{
	string decryptedStr = str;
	decryptedStr.erase(find(decryptedStr.begin(), decryptedStr.end(), (char)-52), decryptedStr.end());
	string result = xor_crypt(encryptionKey, decryptedStr);

	return result;
}





