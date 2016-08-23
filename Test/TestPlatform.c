#define PLAT Platform/Desktop/Darwin/

// Macro for adding quotes
#define STRINGIFY(X) STRINGIFY2(X)
#define STRINGIFY2(X) #X

// Macros for concatenating tokens
#define CAT(X,Y) CAT2(X,Y)
#define CAT2(X,Y) X##Y
#define CAT_2 CAT
#define CAT_3(X,Y,Z) CAT(X,CAT(Y,Z))
#define CAT_4(A,X,Y,Z) CAT(A,CAT_3(X,Y,Z))

#define FOO Platform
#define INCLUDE_FILE(HEAD,TAIL) STRINGIFY( CAT_3(HEAD,FOO,TAIL) )

#define head1 "bar/"

//#include INCLUDE_FILE(head1, tail.h)

#define F(X) "Cplus/Platform/" ## X

//#include F(foo.h)


