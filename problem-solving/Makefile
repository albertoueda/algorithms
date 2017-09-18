PROG  = xxx
ENTRA = yyy
SAI   = zzz

CFLAGS = -Wall -ansi -pedantic -g -O2 -I.
# -std=c++11

LDLIBS = -lm
# para o caso de usar sqrt, sin, cos, etc.


default : 
	@echo ""
	gcc $(CFLAGS) $(PROG).c $(LDLIBS) -o $(PROG)
	@echo ""
	@echo "-----------------------------------"
	@echo "Teste:"
	-$(PROG) <$(ENTRA) >$(SAI)
	cat $(SAI)
