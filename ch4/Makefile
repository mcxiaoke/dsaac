SUBDIRS=

#.PHONY: subdirs $(SUBDIRS)
#subdirs: $(SUBDIRS)

all:
	@echo "Build all sub directories"
	for subdir in $(SUBDIRS);do \
	$(MAKE) -C $$subdir; \
	done
clean:
	@echo "Clean all sub directories"
	for subdir in $(SUBDIRS);do \
	$(MAKE) clean -C $$subdir; \
	done