.PHONY: clean All

All:
	@echo ----------Building project:[ stack_use_array - Debug ]----------
	@cd "stack_use_array" && "mingw32-make.exe"  -j 2 -f "stack_use_array.mk"
clean:
	@echo ----------Cleaning project:[ stack_use_array - Debug ]----------
	@cd "stack_use_array" && "mingw32-make.exe"  -j 2 -f "stack_use_array.mk" clean
