SUBDIRS=list_double list_simple queue_array \
	queue_list stack_array stack_list sort_bucket

#.PHONY: subdirs $(SUBDIRS)
#subdirs: $(SUBDIRS)

all:
	@echo "Build all sub directories"
	for dir in $(SUBDIRS);do \
	$(MAKE) -C $$dir; \
	done
clean:
	@echo "Clean all sub directories"
	for dir in $(SUBDIRS);do \
	$(MAKE) clean -C $$dir; \
	done