#include <iostream>
#include <iomanip> 
#include <string> 
using namespace std;
struct patient
{
	int id;
	string name; 
};  
struct clinic 
{
	int id;
	string namedoctor; 
};
struct curClinic 
{
	patient pat; 
	clinic cli;	
}; 
struct List 
{
	curClinic infor;
	List *next; 
}; 
typedef struct List* list;
struct queueClinic 
{
	clinic data;
	queueClinic *next;
}; 
typedef struct queueClinic* qC;
struct queuePatient 
{
	patient data;
	queuePatient *next;
};
typedef struct queuePatient* qP;
struct stackPatient {
	patient data;
	stackPatient *next; 
}; 
typedef struct stackPatient* sP; 
void inputPatient(patient &p);
void inputClinic(clinic &c);
void setOutPatient();
void setOutClinic();
void setOutListCli();
void outPatient(patient p);
void outClinic(clinic c);
void outListCli(curClinic c);
bool emptyList(list l);
int size(list l);
list createList(patient p, clinic q);
void inputList(list &l, list tmp);
void delList(list &l, qC &c);
int searchID(list l, int id);
void outputList(list l);
bool emptyQuePat(qP p);
int sizeQuePat(qP p);
qP createPat(patient p);
void pushQuePat(qP &q, patient p);
void popQuePat(qP &q, patient &p);
void outQuePat(qP q);
int search(qP p, int id);
bool emptyQueCli(qC p);
int sizeQueCli(qC p);
qC createCli(clinic p);
void pushQueCli(qC &q, clinic p);
void popQueCli(qC &q, clinic &p);
void outQueCli(qC q);
void inputDataCli(qC &b, int n);
void inputDataPat(qP &a, int n);
void norData(list &l, qP &r, qC &t, int a, int b);
void inputPatient(patient &p) 
{
	cout << "Nhap ma benh nhan: ";
	cin >> p.id;
	cin.ignore();
	cout << "Nhap ten benh nhan: ";
	getline(cin, p.name);
}
void inputClinic(clinic &c) 
{
	cout << "Nhap ma phong benh: ";
	cin >> c.id;
	cout << "Nhap ten bac si: ";
	cin.ignore();
	getline(cin, c.namedoctor);
}
void setOutPatient() 
{
	cout << left << setw(15) << "MA BN";
	cout << left << setw(30) << "TEN BN" << endl;
	cout << left << setfill('-') << setw(45) << "-"<< setfill(' ') << endl;
}
void setOutClinic() {
	cout << left << setw(15) << "MA PHONG";
	cout << left << setw(30) << "TEN BAC SI" << endl;
	cout << left << setfill('-') << setw(45) << "-"<< setfill(' ') << endl;
}
void setOutListCli() {
	cout << left << setw(15) << "MA PHONG";
	cout << left << setw(30) << "TEN BAC SI";
	cout << left << setw(15) << "MA BN";
	cout << left << setw(30) << "TEN BN" << endl;
	cout << left << setfill('-') << setw(90) << "-"<< setfill(' ') << endl;
} 
void outPatient(patient p) 
{
	cout << left << setw(15) << p.id;
	cout << left << setw(30) << p.name << endl;
}
void outClinic(clinic c) {
	cout << left << setw(15) << c.id;
	cout << left << setw(30) << c.namedoctor << endl;
}
void outListCli(curClinic c) 
{
	cout << left << setw(15) << c.cli.id;
	cout << left << setw(30) << c.cli.namedoctor;
	cout << left << setw(15) << c.pat.id;
	cout << left << setw(30) << c.pat.name<< endl;
}
bool emptyList(list l) 
{
	return l == NULL;
}
int size(list l) 
{
	int cnt = 0;
	while(l != NULL) 
	{
		++cnt;
		l = l->next;
	}
	return cnt;
}
list createList(patient p, clinic q) 
{
	list tmp = new List();
	tmp->infor.pat = p;
	tmp->infor.cli = q;
	tmp->next = NULL;
	return tmp;
}
void inputList(list &l, list tmp) 
{
	if(l == NULL) 
		l = tmp;
	else 
	{
		list k = l;
		while(k->next != NULL) 
		{
			k = k->next;
		}
		k->next = tmp;
	}
}
int searchID(list l, int id) 
{
	int pos = 1;
	if(l == NULL) {
		cout << "Danh sach rong " << endl;
		return -1;
	}
	else 
	{
		list p = l;
		while(p != NULL) {
			if(p->infor.pat.id == id)
			{
				return pos;
			}
			else 
			{
				pos++;
				p = p->next;
			}
		}
	}
}
void delList(list &l, qC &c) 
{
	int pos, id;
	cout << "Nhap ma benh nhan can xoa: ";
	cin >> id;
	pos = searchID(l, id);
	list j = NULL, k = l;
	for(int i = 1; i <= pos - 1; i++) 
	{
		j = k;
		k = k->next;
	}
	pushQueCli(c, k->infor.cli);
	if(j == NULL)
		l = l->next;
	else
		j->next = k->next;
}
void outputList(list l)
{
 	if(l == NULL) 
	{
		cout << "Danh sach rong" << endl;
 		return;
	}
	else 
	{
		setOutListCli();
		while(l != NULL) 
		{
			outListCli(l->infor);
			l = l->next;
		}
		cout << endl;
	}
}
bool emptyQuePat(qP p) 
{
	return p == NULL;
}
int sizeQuePat(qP p)
{
	int cnt = 0;
	while(p != NULL) 
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}
qP createPat(patient p) 
{
	qP tmp = new queuePatient();
	tmp->data = p;
	tmp->next = NULL;
	return tmp;
}

void pushQuePat(qP &q, patient p) 
{
	qP tmp = createPat(p);
	if(q == NULL) 
	{
		q = tmp;
	}
	else 
	{
		tmp->next = q;
		q = tmp;
	}
}
void popQuePat(qP &q, patient &p) 
{
	if(q == NULL) 
	{
		cout << "Hang doi benh nhan rong" << endl;
		return;
	}
	qP s = q;
	qP t = NULL;
	while(s->next != NULL) 
	{
		t = s;
		s = s->next;
	}
	p = s->data;
	if(t == NULL) 
		q = NULL; 
	else 
		t->next = NULL;	
}
int search(qP q, int id) 
{
	int pos = 1;
	if(q == NULL) 
	{
		cout << "Hang doi benh nhan rong." << endl;
		return -1;
	}
	else 
	{
		qP p = q;
		while(p != NULL)
		 {
			if(p->data.id == id)
			{
				return pos;
			}
			else 
			{
				pos++;
				p = p->next;
			}
		}
	}
	return -1;
}
void outQuePat(qP q) 
{
	if(q == NULL) 
	{
		cout << "Hang doi benh nhan rong" << endl;
		return;
	}
	setOutPatient();
	while(q != NULL) 
	{
		outPatient(q->data);
		q = q->next;
	}
	cout << endl;
}
bool emptyQueCli(qC p) 
{
	return p == NULL;
}
int sizeQueCli(qC p)
{
	int cnt = 0;
	while(p != NULL) 
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}
qC createCli(clinic p) 
{
	qC tmp = new queueClinic();
	tmp->data = p;
	tmp->next = NULL;
	return tmp;
}
void pushQueCli(qC &q, clinic p) 
{
	qC tmp = createCli(p);
	if(q == NULL) 
	{
		q = tmp;
	}
	else 
	{
		tmp->next = q;
		q = tmp;
	}
}
void popQueCli(qC &q, clinic &p) 
{
	if(q == NULL) 
	{
		cout << "Hang doi phong kham rong" << endl;
		return;
	}
	qC s = q;
	qC t = NULL;
	while(s->next != NULL) 
	{
		t = s;
		s = s->next;
	}
	p = s->data;
	if(t ==NULL) 
		q = NULL; 
	else 
		t->next = NULL;	
}
void outQueCli(qC q) 
{
	if(q == NULL) {
		cout << "Hang doi phong kham rong" << endl;
		return;
	}
	setOutClinic();
	while(q != NULL) 
	{
		outClinic(q->data);
		q = q->next;
	}
	cout << endl;
}
//Input data
void inputDataCli(qC &b, int n) 
{ 
	clinic h;
	for(int i = 1; i <= n; i++) 
	{
		inputClinic(h);
		pushQueCli(b, h); 
	} 
} 
void inputDataPat(qP &a, int n) 
{ 
	patient g;
	for(int i = 1; i <= n; i++) 
	{
		inputPatient(g);
		pushQuePat(a, g); 
	} 
}
/* Normalize data */
//Delete patient from queue
void delQuePat(qP &r) 
{
	patient g, v;
	int w, f, z, pos;
	qP s = NULL;
	w = sizeQuePat(r);
	cout << "Nhap so benh nhan dang cho: "; cin >> z;
	if(z > w) 
	{
		cout << "So luong khong hop le" << endl;
		return;
	}
	for(int j = 1; j <= z; j++)
	{
		int k = sizeQuePat(r);
		do
		{
			cout << "Nhap ma benh nhan dang cho: "; cin >> f;
			pos = search(r, f);
		} while(pos == -1);
		if(pos == k) 
		{
			popQuePat(r, v);
		}
		else 
		{
			for(int i = k; i >= 1; i--)
			{
				if(i == pos) {
					popQuePat(r, v);
				}
				else 
				{
					popQuePat(r, g);
					pushQuePat(s, g);
				}
			}
			while(s != NULL) 
			{
				popQuePat(s, g);
				pushQuePat(r, g);
			}
		}
	}
}
void norData(list &l, qP &r, qC &t, int a, int b) 
{
	patient g, v;
	clinic h, j;
	if(a >= b)
	{
		for(int i = 1; i <= b; i++) 
		{
			popQuePat(r, g);
			popQueCli(t, h);
			list tmp = createList(g, h);
			inputList(l, tmp);
		}
	}
	else if(a < b){
		if(t != NULL)
		{
			for(int i = 1; i <= a; i++) 
			{
				popQuePat(r, v);
				popQueCli(t, j);
				list tmp = createList(v, j);
				inputList(l, tmp);
			}
		}
		int x;
		cout << "Vui long cho" << endl;
		cout << "Co = 1\nKhong = 2) : "; cin >> x; 
		if(x == 1) return;
		if(x == 2)
		{
			delQuePat(r);		
		}
	}
}
/*************************************/
int main() {
	list l = NULL;
	qP a = NULL;
	qC b = NULL;
	sP st = NULL;
	patient c;
	clinic d;
	int x, y;
	
	cout << "Nhap so luong phong: ";
	cin >> y;
	inputDataCli(b, y);
	
	while(true) {
		cout << "********************MENU********************" << endl;
		cout << "* 1. In danh sach phong hien co     *" << endl;
		cout << "* 2. In danh sach benh nhan dang cho   *" << endl;
		cout << "* 3. In danh sach phong kham dang su dung     *" << endl;
		cout << "* 4. Xoa benh nhan tu danh sach            *" << endl;
		cout << "* 5. Xoa benh nhan khoi hang doi  *" << endl;
		cout << "* 6. Them benh nhan vao phong kham         *" << endl;
		cout << "* 0. Thoat chuong trinh                      *" << endl;
		cout << "********************************************" << endl;
		cout << "Nhap lua chon : "; cin >> x;
		switch(x)
		{
			case 1:
			{
				outQueCli(b);
				break;
			}
			case 2:
			{
				outQuePat(a);
				break;
			}
			case 3:
			{
				outputList(l);
				break;
			}
			case 4:
			{
				if(l == NULL) cout << "Danh sach rong" << endl;
				else delList(l, b);
				break;
			}
			case 5:
			{
				if(a == NULL) cout << "Hang di benh nhan rong" << endl;
				else delQuePat(a);
				break;
			}
			case 6:
			{
				int k;
				cout << "Nhap so luong benh nhan: "; cin >> k;
				inputDataPat(a, k);
				norData(l, a, b, sizeQueCli(b), k);
				break;
			}
			case 0:
			{
				cout << "Thoat chuong trinh" << endl;
				return 0;
			}
		}
	} 
	return 0;
}
