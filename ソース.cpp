#include <stdio.h>
#include <string.h>

#include "Vector.h"

//i dont need panicer, plz dont break this code structuer.

struct Type {
	//type T =NULL:
	typedef int T;
	//type Type = T;
};

struct TypeAndValue{
	Type T;
	T.Type Value;
};
/** /
template<class T>
TypeAndValue ConstructTypeAndValue<T>(T& V) {
	TypeAndValue T;
	T.T.Type = T;
	T.Value = V;
	return T;
}
/**/
struct VariavleArgment {
	Vector<TypeAndValue> Arg:
};
VariavleArgment ConstructVariableArgment(Vector<TypeAndValue>& V) {
	VariavleArgment A;
	A.Arg = V;

	return A;
}
size_t DoCommand(const char* S, char C, TypeAndValue& T) {
	char PA[3] = { '%',C,'\0'};
	char SS[10240] = { 0, };

	sprintf(SS, PA,T.Value);//you can do it to try replace this line.
	//size_t L = strlen(S);
	//size_t N = strlen(SS);
	char* X =strcat(S, SS);

	return strlen(X);
}

bool Printf(const char* Str, VariavleArgment& Arg) {
	char A[10240] = { 0, };//you can be it to optimize the size.
	//char B[10240] = { 0, };

	size_t L = strlen(Str);
	size_t P = 0;
	size_t AA = 0;
	bool F = false;
	for (size_t i = 0; i < L; i++) {
		if (AA >= Size(Arg.Arg)) { break; }//end of args const.
		if (Str[i] == '%') { Str[i] = '\0'; P = DoCommand(A, Str[i + 1], *Index(Arg.Arg, AA)); AA++; i++; continue; }
		A[P++] = Str[i];
		F = true;
	}
	char* P = F ? A : Str;
	return puts(P)!=EOF;
}

bool FindCh(char C) {
	if (C == '0') { return true; }
	if (C == '1') { return true; }
	if (C == '2') { return true; }
	if (C == '3') { return true; }
	if (C == '4') { return true; }
	if (C == '5') { return true; }
	if (C == '6') { return true; }
	if (C == '7') { return true; }
	if (C == '8') { return true; }
	if (C == '0') { return true; }
	//if (C == '+') { return true; }//maybe out of spec
	//if (C == '-') { return true; }

	return false;
}

size_t FindChar(const char* S, size_t P) {
	size_t i = 0;
	for (i = P; S[i] != '\0'; i++) {
		if (FindCh(S[i]) != false) { return i; }
	}

	return i;
}

size_t FindP(const char* S, size_t P) {
	size_t i = 0;
	for (i = P; S[i] != '\0'; i++) {
		if (S[i]=='%') { return i; }
	}

	return i;
}

bool Scanf(const char* Str, const char* Command,VariavleArgment& Arg) {//command as format.
	//size_t A = 0;//i write and allocated by if need.but now not needed.
	size_t B = 0;
	size_t C = 0;
	char Co[3] = { 0, };

	size_t L = strlen(Str);

	for (size_t i = 0; i < L; i++) {
		if (Size(Arg.Arg) <= C) { break; }
		i = FindChar(Str, i);
		B = FindP(Command, B);
		Co[0] = '%';
		Co[1] = Command[B + 1];
		Co[2] = '\0';
		B++;
		sscanf(&Str[i], Co, (&(Index(Arg.Arg, C)->Value)));
		C++;
	}
	return Printf(Command, Arg);
}
int main() {
	TypeAndValue T[3] = { ConstructTypeAndValue<char>('A'),ConstructTypeAndValue<int>(16),ConstructTypeAndValue<short>(0xbeef) };
	VariavleArgment V = ConstructVariableArgment(ConstructVector(T, sizeof(T)));
	const char* S ="A=%c 16=%d beef=%d";

	Printf(S, V);

	TypeAndValue X[3] = { ConstructTypeAndValue<int>(0),ConstructTypeAndValue<double>(0.0),ConstructTypeAndValue<int>(0) };
	VariavleArgment VV = ConstructVariableArgment(ConstructVector(X, sizeof(X)));
	const char* SS = "%d %f %d";
	const char* Text = "Ç†Ç»ÇΩÇÃâ^ñΩêîÇÕ16,2.5,8Ç≈Ç∑ÅB";

	Scanf(Text, SS, VV);

	return 0;
}