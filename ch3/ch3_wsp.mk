.PHONY: clean All

All:
	@echo ----------Building project:[ doublelist - Debug ]----------
	@cd "doublelist" && "mingw32-make.exe"  -j 2 -f "doublelist.mk"
clean:
	@echo ----------Cleaning project:[ doublelist - Debug ]----------
	@cd "doublelist" && "mingw32-make.exe"  -j 2 -f "doublelist.mk" clean
