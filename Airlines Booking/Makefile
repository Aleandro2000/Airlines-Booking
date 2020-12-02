build:
	(mkdir Linux&&g++ "Airlines Booking".cpp -o ./Linux/"Airlines Booking")||g++ "Airlines Booking".cpp -o ./Linux/"Airlines Booking"
	(mkdir Windows-32&&i686-w64-mingw32-g++ -o ./Windows-32/"Airlines Booking".exe "Airlines Booking".cpp)||i686-w64-mingw32-g++ -o ./Windows-32/"Airlines Booking".exe "Airlines Booking".cpp
	(mkdir Windows-64&&x86_64-w64-mingw32-g++ -o ./Windows-64/"Airlines Booking".exe "Airlines Booking".cpp)||x86_64-w64-mingw32-g++ -o ./Windows-64/"Airlines Booking".exe "Airlines Booking".cpp
linux-run:
	./Linux/"Airlines Booking"
