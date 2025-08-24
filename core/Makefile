LV2DIR ?= /usr/lib/lv2

PLUGIN = stereo-sum
BUNDLE = $(PLUGIN).lv2
CFLAGS = -fPIC -O2 -Wall
LDFLAGS = -shared

all: $(BUNDLE)

$(BUNDLE): $(PLUGIN).so manifest.ttl $(PLUGIN).ttl
	mkdir -p $(BUNDLE)
	cp $(PLUGIN).so manifest.ttl $(PLUGIN).ttl $(BUNDLE)/

$(PLUGIN).so: $(PLUGIN).c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

install: all
	mkdir -p $(LV2DIR)
	cp -r $(BUNDLE) $(LV2DIR)/

clean:
	rm -f $(PLUGIN).so
	rm -rf $(BUNDLE)
