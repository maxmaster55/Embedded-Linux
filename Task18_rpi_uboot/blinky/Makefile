CROSS = aarch64-rpi3-linux-gnu-

CC = $(CROSS)gcc
OBJCOPY = $(CROSS)objcopy
CFLAGS = -ffreestanding -nostdlib -nostartfiles -nodefaultlibs -O2 -Iinc -Wall
LDFLAGS = -T linker.ld -nostdlib -nostartfiles -nodefaultlibs

BUILD_DIR = build
ELF = $(BUILD_DIR)/rpi_app.elf
BIN = $(BUILD_DIR)/rpi_app

all:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/start.S -o $(BUILD_DIR)/start.o
	$(CC) $(CFLAGS) -c src/main.c -o $(BUILD_DIR)/main.o
	$(CC) $(LDFLAGS) $(BUILD_DIR)/start.o $(BUILD_DIR)/main.o -o $(ELF)
	$(OBJCOPY) -O binary $(ELF) $(BIN)
	@echo "Binary size: $$(stat -c%s $(BIN)) bytes"
	@echo "Copying to TFTP server..."
	cp $(BIN) /srv/tftp/rpi_app

clean:
	rm -rf $(BUILD_DIR)

dump: $(ELF)
	$(CROSS)objdump -D $(ELF) | less

info: $(ELF)
	$(CROSS)readelf -h $(ELF)
	$(CROSS)readelf -S $(ELF)