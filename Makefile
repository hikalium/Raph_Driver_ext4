MAIN = umodule

default:
	make -C source

.PHONY: run
run:
	make default
	@./$(MAIN)

.PHONY: clean
clean:
	make -C source clean
