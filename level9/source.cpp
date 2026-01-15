#include <cstdlib>
#include <cstring>

class N {
private:
  void *pointer;
  char buffer[100];
  int number;

public:
  N(int n);
  void *setAnnotation(char *s);
};

N::N(int n) {
  *(int *)this = 0x08048848;
  *((int *)this + 26) = n;
}

void *N::setAnnotation(char *s) {
  size_t v2; // eax

  v2 = strlen(s);
  return memcpy((char *)this + 4, s, v2);
}

int __cdecl N::operator+(int a1, int a2) {
  return *(int *)(a1 + 104) + *(int *)(a2 + 104);
}

int __cdecl N::operator-(int a1, int a2) {
  return *(int *)(a1 + 104) - *(int *)(a2 + 104);
}

int main(int argc, const char **argv, const char **envp) {
  N *v3; // ebx
  N *v4; // ebx
  N *v6; // [esp+1Ch] [ebp-8h]

  if (argc <= 1) {
    exit(1);
  }
  v3 = (N *)operator new(0x6Cu);
  N::N(v3, 5);
  v6 = v3;
  v4 = (N *)operator new(0x6Cu);
  N::N(v4, 6);
  N::setAnnotation(v6, (char *)argv[1]);
  return (**(int(__cdecl ***)(N *, N *))v4)(v4, v6);
}
