.PHONY: clean All

All:
	@echo ----------Building project:[ queue_use_list - Debug ]----------
	@cd "queue_use_list" && "mingw32-make.exe"  -j 2 -f "queue_use_list.mk"
clean:
	@echo ----------Cleaning project:[ queue_use_list - Debug ]----------
	@cd "queue_use_list" && "mingw32-make.exe"  -j 2 -f "queue_use_list.mk" clean
