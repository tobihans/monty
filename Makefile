TARGET := monty

BUILD_DIR := ./build
SRC_DIR := ./

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC = gcc
CPPFLAGS := $(INC_FLAGS) -MMD -MP

build: CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu89
release: CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

.PHONY: build
build: $(OBJS)
	@$(CC) $(OBJS) -o $(BUILD_DIR)/$(TARGET) $(LDFLAGS)

.PHONY: release
release: $(OBJS)
	@$(CC) $(OBJS) -o $(BUILD_DIR)/$(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: run
run: build
	@$(BUILD_DIR)/$(TARGET)

.PHONY: memcheck
memcheck: release
	@valgrind $(BUILD_DIR)/$(TARGET)

.PHONY: fmt-check
fmt-check:
	@betty *.c *.h

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
