#include <stdio.h>
#include <string.h>

#include "Vector.h"
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

	sprintf(SS, PA,T.Value);
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
	for (size_t i = 0; i < L; i++) {
		if (AA >= Size(Arg.Arg)) { break; }//end of args const.
		if (Str[i] == '%') { Str[i] = '\0'; P = DoCommand(A, Str[i + 1], *Index(Arg.Arg, AA)); AA++; i++; continue; }
		A[P++] = Str[i];
	}

	return puts(A)!=EOF;
}

int main() {
	TypeAndValue T[3] = { ConstructTypeAndValue<char>('A'),ConstructTypeAndValue<int>(16),ConstructTypeAndValue<short>(0xbeef) };
	VariavleArgment V = ConstructVariableArgment(ConstructVector(T, sizeof(T)));
	const char* S ="A=%c 16=%d beef=%d";

	Printf(S, V);

	return 0;
}