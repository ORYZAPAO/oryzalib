TARGET=sc1.rom

$(TARGET) : mymsx1.c
	#zcc +x1 -create-app -lm myx1.c
	#zcc +msx -create-app -subtype=rom mymsx1.c
	zcc +msx -vn -llib3d  -lm -lndos -create-app -DAMALLOC -subtype=rom mymsx1.c -o $@

clean :
	rm $(TARGET)
	rm *.bin
	rm zcc_opt.def
