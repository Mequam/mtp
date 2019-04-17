build: GenXY.cc Race.h XYRng.h
	g++ GenXY.cc -o mtp
clean: mtp
	rm mtp
install: mtp
	cp mtp /usr/bin/mtp
uninstall: /usr/bin/mtp
	rm /usr/bin/mtp
