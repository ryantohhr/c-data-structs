.PHONY: all run clean

BUILD_DIR := build

all:
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles"
	cmake --build $(BUILD_DIR)

clean:
	rm -rf build

run: 
ifndef TARGET
	$(error TARGET is not set. Example usage: make run TARGET=linkedlist)
endif
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles"
	cmake --build $(BUILD_DIR) --target $(TARGET)
	./$(BUILD_DIR)/$(TARGET)
