#include "classlearn.h"
#include "myclasses.h"

//��ʽ����

namespace ch13 {
	//typedef std::ios_base::fmtflags format;
	//typedef std::streamsize precis;
	//format setFormat();
	//void restore(format f, precis p);

	//// Brass�෽��
	//Brass::Brass(const std::string& s, const long& an , const double& bal):
	//	fullName(s),accNum(an),balance(bal) { };
	//void Brass::Deposit(double amt) {
	//	if (amt < 0)
	//		cout << "��������븺ֵ���������˳���\n";
	//	else
	//		balance += amt;
	//}
	//void Brass::Withdraw(double amt) {
	//	//���ø�ʽΪ###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	if (amt < 0)
	//		cout << "������ȡ����ֵ��ȡ������˳���\n";
	//	else if (amt <= balance)
	//		balance -= amt;
	//	else
	//		cout << "ȡ����$" << amt
	//		<< "��������Ĵ��$" << balance
	//		<< ",ȡ��ʧ�ܣ�\n";
	//	restore(initialState, prec);
	//};
	//double Brass::Balance()const {
	//	return balance;
	//};
	//void Brass::ViewAcct() const {
	//	//���ø�ʽΪ###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	cout << "�ͻ���: " << fullName << endl;
	//	cout << "�˻���ţ� " << accNum << endl;
	//	cout << "�˻������ " << balance << endl;
	//	restore(initialState, prec);
	//};
	//Brass::~Brass() { };
	////BrassPlus �෽��
	//BrassPlus::BrassPlus(const std::string& s, const long& an ,
	//	const double& bal, const double& ml, const double r):
	//	Brass(s, an, bal), maxLoan(ml), rate(r) {
	//	owesBank = 0;
	//};
	//BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :
	//	Brass(ba), maxLoan(ml), rate(r) {
	//	owesBank = 0;
	//};
	//void BrassPlus::ViewAcct()const {
	//	//���ø�ʽΪ###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	Brass::ViewAcct();
	//	cout << "���͸֧��ȣ� $" << maxLoan << endl;
	//	cout << "��ǰǷ� $" << owesBank << endl;
	//	cout.precision(3);
	//	cout << "Ƿ�����ʣ� " << rate * 100 << "%\n";
	//	restore(initialState, prec);
	//};
	//void BrassPlus::Withdraw(double amt) {
	//	//���ø�ʽΪ###.##
	//	format initialState = setFormat();
	//	precis prec = cout.precision(2);
	//	double bal = Balance();
	//	if (amt < bal)
	//		Brass::Withdraw(amt);
	//	else if (amt <= bal + maxLoan - owesBank) {
	//		double advance = amt - bal;
	//		owesBank += advance * (1.0 + rate);
	//		cout << "����͸֧�� $" << advance << endl;
	//		cout << "����͸֧��֧����Ϣ�� $" << advance * rate << endl;
	//		Deposit(advance);
	//		Brass::Withdraw(amt);
	//	}
	//	else
	//		cout << "����͸֧���ö��,����ȡ����\n";
	//	restore(initialState, prec);
	//};
	//format setFormat() {
	//	//���ø�ʽΪ###.##
	//	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	//}
	//void restore(format f, precis p) {
	//	cout.setf(f, std::ios_base::floatfield);
	//	cout.precision(p);
	//}

	using std::ios_base;
	//AcctABC �෽��
	AcctABC::AcctABC(const std::string& s, long an, double bal):fullName(s),acctNum(an),balance(bal) {};
	void AcctABC::Deposit(double amt) {
		if (amt < 0)
			cout << "��������븺ֵ��������ȡ����\n";
		else
			balance += amt;
	}
	void AcctABC::Withdraw(double amt) {
		balance -= amt;
	}
		//��ʽ������ı����෽��
	AcctABC::Formatting AcctABC::SetFormat()const {
		//���ø�ʽΪ###.##
		Formatting f;
		f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
		f.pr = cout.precision(2);
		return f;
	}
	void AcctABC::Restore(Formatting& f)const {
		cout.setf(f.flag, ios_base::floatfield);
		cout.precision(f.pr);
	}
	
	//Brass�෽��
	void Brass::Withdraw(double amt) {
		double bal = Balance();
		if (amt < 0)
			cout << "ȡ��������Ϊ��ֵ��ȡ����̽���!\n";
		else if (amt > bal)
			cout << "ȡ������������ȡ��ʧ��!\n";
		else
			AcctABC::Withdraw(amt);
	}
	void Brass::ViewAcct()const {
		Formatting f = SetFormat();
		cout << "�˻�������������" << FullName()<<endl;
		cout << "�˻����룺" << AcctName() << endl;
		cout << "�˻������" << Balance() << endl;
		Restore(f);
	}
	//BrassPlus �෽��
	BrassPlus::BrassPlus(const std::string& s, long an, double bal,
		double ml, double r):AcctABC(s,an,bal),maxLoan(ml),rate(r) {
		owesBank = 0;
	};
	BrassPlus::BrassPlus(const Brass& ba, double ml, double r) :AcctABC(ba), maxLoan(ml), rate(r) {};
	void BrassPlus::Withdraw(double amt) {
		double bal = AcctABC::Balance();
		if (amt <= bal)
			AcctABC::Withdraw(amt);
		else if (amt > bal + maxLoan - owesBank)
				cout << "������ö�Ȳ��㣬ȡ��ʧ�ܣ�" << endl;
		else {
			double temp = amt - bal;
			owesBank += temp + temp*rate;
			cout << "����͸֧��$" << temp << endl;
			cout << "����͸֧���������Ϣ��$" << temp * rate << endl;
			Deposit(temp);
			AcctABC::Withdraw(amt);
		}
	}
	void BrassPlus::ViewAcct()const {
		Formatting f = SetFormat();
		cout << "�˻�������������" << FullName() << endl;
		cout << "�˻����룺" << AcctName() << endl;
		cout << "�˻������" << Balance() << endl;
		cout << "���͸֧���: " << maxLoan << endl;
		cout << "��ǰǷ��: " << owesBank << endl;
		cout << "͸֧����: " << rate * 100 << "%\n";
		Restore(f);
	}

	//baseDMA�෽��
	baseDMA::baseDMA(const char* l, int r) {
		label = new char[std::strlen(l) + 1];
		std::strcpy(label, l);
		rating = r;
	}
	baseDMA::baseDMA(const baseDMA& rs) {
		label = new char[std::strlen(rs.label) + 1];
		std::strcpy(label, rs.label);
		rating = rs.rating;
	}
	baseDMA::~baseDMA() {
		delete[] label;
	}
	baseDMA& baseDMA::operator=(const baseDMA& rs) {
		if (&rs == this)
			return *this;
		delete[]label;
		label = new char[std::strlen(rs.label) + 1];
		std::strcpy(label, rs.label);
		rating = rs.rating;
		return *this;
	}
		//��Ԫ��������
	std::ostream& operator<<(std::ostream& os, const baseDMA& rs) {
		os << "Label: " << rs.label << endl;
		os << "Rating: " << rs.rating << endl;
		return os;
	}
	//lacksDMA����
	lacksDMA::lacksDMA(const char* l,int r, const char* c) :
		baseDMA(l, r) {
		std::strncpy(color, c, COL_LEN-1);
		color[COL_LEN - 1] = '\0';
	}
	lacksDMA::lacksDMA(const baseDMA& rs, const char* c) :
		baseDMA(rs) {
		std::strncpy(color, c, COL_LEN - 1);
		color[COL_LEN - 1] = '\0';
	}
	std::ostream& operator<<(std::ostream& os, const lacksDMA& ls) {
		os << (const baseDMA&)ls;
		os << "Color: " << ls.color << endl;
		return os;
	}
	//hasDMA����
	hasDMA::hasDMA(const char* l, int r, const char* s) :
		baseDMA(l, r) {
		style = new char[std::strlen(s) + 1];
		std::strcpy(style, s);
	}
	hasDMA::hasDMA(const baseDMA& rs, const char* s) :
		baseDMA(rs) {
		style = new char[std::strlen(s) + 1];
		std::strcpy(style, s);
	}
	hasDMA::hasDMA(const hasDMA& hs):
		baseDMA(hs) {
		style = new char[std::strlen(hs.style) + 1];
		std::strcpy(style, hs.style);
	}
	hasDMA& hasDMA::operator=(const hasDMA& hs) {
		if (this == &hs)
			return *this;
		baseDMA::operator=(hs);
		delete[] style;
		style = new char[std::strlen(hs.style) + 1];
		std::strcpy(style, hs.style);
		return *this;
	}
	hasDMA::~hasDMA() {
		delete[]style;
	}
	std::ostream& operator<<(std::ostream& os, const hasDMA& hs) {
		os << (const baseDMA&)hs;
		os << "Style: " << hs.style << endl;
		return os;
	}


}