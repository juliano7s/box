include ../default.mk

SUBDIRS = ./TileMatrixBasic ./AnimationBasic ./SpriteBasic

all :
	@for i in $(foreach d,$(SUBDIRS),$(d)); do \
	$(MAKE) -C $$i; \
	done;

clean :
	@for i in $(foreach d,$(SUBDIRS),$(d)); do \
	$(MAKE) -C $$i $@; \
	done;
