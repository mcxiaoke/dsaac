.PHONY: clean All

All:
	@echo ----------Building project:[ list - Debug ]----------
	@cd "list" && "mingw32-make.exe"  -j 2 -f "list.mk"
clean:
	@echo ----------Cleaning project:[ list - Debug ]----------
	@cd "list" && "mingw32-make.exe"  -j 2 -f "list.mk" clean
