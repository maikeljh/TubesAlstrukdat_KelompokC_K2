CC = gcc -o
dir=src/lib/adt/
dir_s= build/lib/adt/sederhana/
dir_ns= build/lib/adt/non_sederhana/
dir_main =src/main.c $(dir)wordmachine/wordmachine.c $(dir)wordmachine/charmachine.c $(dir)wordfilemachine/wordfilemachine.c $(dir)wordfilemachine/charfilemachine.c $(dir)sederhana/time/time.c $(dir)sederhana/point/point.c $(dir)prioqueue/prioqueuetime.c  $(dir)kulkas/kulkas.c src/lib/adt/sederhana/simulator/simulator.c $(dir)matrix/matrix.c $(dir)sederhana/makanan/makanan.c $(dir)tree/tree.c $(dir)notifikasi/notifikasi.c $(dir)set/set.c $(dir)stack/stack.c
dir_kulkas = $(dir)kulkas/kulkas.c
dir_matrix = $(dir)matrix/matrix.c
dir_liststatik = $(dir)liststatik/liststatik.c
dir_notifikasi = $(dir)notifikasi/notifikasi.c
dir_prioqueue = $(dir)prioqueue/prioqueuetime.c
dir_sederhana = $(dir)sederhana/
dir_makanan = $(dir_sederhana)makanan/makanan.c
dir_point = $(dir_sederhana)point/point.c
dir_simulator = $(dir_sederhana)simulator/simulator.c
dir_time = $(dir_sederhana)time/time.c
dir_set = $(dir)set/set.c
dir_stack = $(dir)stack/stack.c
dir_tree = $(dir)tree/tree.c
dir_wordflm = $(dir)wordfilemachine/wordfilemachine.c
dir_charflm = $(dir)wordfilemachine/charfilemachine.c
dir_wordm = $(dir)wordmachine/wordmachine.c
dir_charm = $(dir)wordmachine/charmachine.c

all:
	$(CC) build/main.exe $(dir_main)

	$(CC) $(dir_ns)main_kulkas.exe $(dir)kulkas/main_kulkas.c $(dir_kulkas) $(dir_matrix) $(dir_simulator) $(dir_time) $(dir_wordm) $(dir_notifikasi) $(dir_point) $(dir_prioqueue) $(dir_charm)

	$(CC) $(dir_ns)main_liststatik.exe $(dir)liststatik/main_liststatik.c $(dir_liststatik) $(dir_wordm) $(dir_charm) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_time)

	$(CC) $(dir_ns)main_matrix.exe $(dir)matrix/main_matrix.c $(dir_matrix)

	$(CC) $(dir_ns)main_notifikasi.exe $(dir)notifikasi/main_notifikasi.c $(dir_notifikasi) $(dir_wordm) $(dir_charm)

	$(CC) $(dir_ns)main_prioqueue.exe $(dir)prioqueue/main_prioqueue.c $(dir_prioqueue) $(dir_time) $(dir_makanan) $(dir_wordm) $(dir_charm) $(dir_wordflm) $(dir_charflm) $(dir_tree) $(dir_notifikasi)

	$(CC) $(dir_s)main_makanan.exe $(dir)sederhana/makanan/main_makanan.c $(dir_makanan) $(dir_time) $(dir_notifikasi) $(dir_wordm) $(dir_charm) $(dir_wordflm) $(dir_charflm) $(dir_tree)

	$(CC) $(dir_s)main-point.exe $(dir)sederhana/point/main_point.c $(dir_point)

	$(CC) $(dir_s)main_simulator.exe $(dir)sederhana/simulator/main_simulator.c $(dir_simulator) $(dir_prioqueue) $(dir_wordm) $(dir_charm) $(dir_time) $(dir_point) $(dir_notifikasi)

	$(CC) $(dir_s)main_time.exe $(dir)sederhana/time/main_time.c $(dir_time)

	$(CC) $(dir_ns)main_set.exe $(dir)set/main_set.c $(dir_set) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_wordm) $(dir_charm) $(dir_time) $(dir_tree) $(dir_simulator) $(dir_notifikasi) $(dir_point) $(dir_prioqueue)

	$(CC) $(dir_ns)main_stack.exe $(dir)stack/main_stack.c $(dir_stack) $(dir_simulator) $(dir_notifikasi) $(dir_time) $(dir_wordflm) $(dir_charflm) $(dir_wordm) $(dir_charm) $(dir_point) $(dir_prioqueue)

	$(CC) $(dir_ns)main_tree.exe $(dir)tree/main_tree.c $(dir_tree) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_time) $(dir_wordm) $(dir_charm)

	$(CC) $(dir_ns)main_wordfilemachine.exe $(dir)wordfilemachine/main_wordfilemachine.c $(dir_wordflm) $(dir_charflm) $(dir_tree) $(dir_matrix) $(dir_point) $(dir_makanan) $(dir_wordm) $(dir_charm) $(dir_time)

	$(CC) $(dir_ns)main_wordmachine.exe $(dir)wordmachine/main_wordmachine.c $(dir_wordm) $(dir_charm)

adt:
	$(CC) $(dir_ns)main_kulkas.exe $(dir)kulkas/main_kulkas.c $(dir_kulkas) $(dir_matrix) $(dir_simulator) $(dir_time) $(dir_wordm) $(dir_notifikasi) $(dir_point) $(dir_prioqueue) $(dir_charm)

	$(CC) $(dir_ns)main_liststatik.exe $(dir)liststatik/main_liststatik.c $(dir_liststatik) $(dir_wordm) $(dir_charm) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_time)

	$(CC) $(dir_ns)main_matrix.exe $(dir)matrix/main_matrix.c $(dir_matrix)

	$(CC) $(dir_ns)main_notifikasi.exe $(dir)notifikasi/main_notifikasi.c $(dir_notifikasi) $(dir_wordm) $(dir_charm)

	$(CC) $(dir_ns)main_prioqueue.exe $(dir)prioqueue/main_prioqueue.c $(dir_prioqueue) $(dir_time) $(dir_makanan) $(dir_wordm) $(dir_charm) $(dir_wordflm) $(dir_charflm) $(dir_tree) $(dir_notifikasi)

	$(CC) $(dir_s)main_makanan.exe $(dir)sederhana/makanan/main_makanan.c $(dir_makanan) $(dir_time) $(dir_notifikasi) $(dir_wordm) $(dir_charm) $(dir_wordflm) $(dir_charflm) $(dir_tree)

	$(CC) $(dir_s)main-point.exe $(dir)sederhana/point/main_point.c $(dir_point)

	$(CC) $(dir_s)main_simulator.exe $(dir)sederhana/simulator/main_simulator.c $(dir_simulator) $(dir_prioqueue) $(dir_wordm) $(dir_charm) $(dir_time) $(dir_point) $(dir_notifikasi)

	$(CC) $(dir_s)main_time.exe $(dir)sederhana/time/main_time.c $(dir_time)

	$(CC) $(dir_ns)main_set.exe $(dir)set/main_set.c $(dir_set) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_wordm) $(dir_charm) $(dir_time) $(dir_tree) $(dir_simulator) $(dir_notifikasi) $(dir_point) $(dir_prioqueue)

	$(CC) $(dir_ns)main_stack.exe $(dir)stack/main_stack.c $(dir_stack) $(dir_simulator) $(dir_notifikasi) $(dir_time) $(dir_wordflm) $(dir_charflm) $(dir_wordm) $(dir_charm) $(dir_point) $(dir_prioqueue)

	$(CC) $(dir_ns)main_tree.exe $(dir)tree/main_tree.c $(dir_tree) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_time) $(dir_wordm) $(dir_charm)

	$(CC) $(dir_ns)main_wordfilemachine.exe $(dir)wordfilemachine/main_wordfilemachine.c $(dir_wordflm) $(dir_charflm) $(dir_tree) $(dir_matrix) $(dir_point) $(dir_makanan) $(dir_wordm) $(dir_charm) $(dir_time)

	$(CC) $(dir_ns)main_wordmachine.exe $(dir)wordmachine/main_wordmachine.c $(dir_wordm) $(dir_charm)

main: 
	$(CC) build/main.exe $(dir_main)

adt_kulkas:
	$(CC) $(dir_ns)main_kulkas.exe $(dir)kulkas/main_kulkas.c $(dir_kulkas) $(dir_matrix) $(dir_simulator) $(dir_time) $(dir_wordm) $(dir_notifikasi) $(dir_point) $(dir_prioqueue) $(dir_charm)

adt_liststatik: 
	$(CC) $(dir_ns)main_liststatik.exe $(dir)liststatik/main_liststatik.c $(dir_liststatik) $(dir_wordm) $(dir_charm) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_time)

adt_matrix:
	$(CC) $(dir_ns)main_matrix.exe $(dir)matrix/main_matrix.c $(dir_matrix)

adt_notifikasi:
	$(CC) $(dir_ns)main_notifikasi.exe $(dir)notifikasi/main_notifikasi.c $(dir_notifikasi) $(dir_wordm) $(dir_charm)

adt_prioqueue:
	$(CC) $(dir_ns)main_prioqueue.exe $(dir)prioqueue/main_prioqueue.c $(dir_prioqueue) $(dir_time) $(dir_makanan) $(dir_wordm) $(dir_charm) $(dir_wordflm) $(dir_charflm) $(dir_tree) $(dir_notifikasi)

adt_makanan:
	$(CC) $(dir_s)main_makanan.exe $(dir)sederhana/makanan/main_makanan.c $(dir_makanan) $(dir_time) $(dir_notifikasi) $(dir_wordm) $(dir_charm) $(dir_wordflm) $(dir_charflm) $(dir_tree)

adt_point:
	$(CC) $(dir_s)main_point.exe $(dir)sederhana/point/main_point.c $(dir_point)

adt_simulator:
	$(CC) $(dir_s)main_simulator.exe $(dir)sederhana/simulator/main_simulator.c $(dir_simulator) $(dir_prioqueue) $(dir_wordm) $(dir_charm) $(dir_time) $(dir_point) $(dir_notifikasi)

adt_time:
	$(CC) $(dir_s)main_time.exe $(dir)sederhana/time/main_time.c $(dir_time)

adt_set:
	$(CC) $(dir_ns)main_set.exe $(dir)set/main_set.c $(dir_set) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_wordm) $(dir_charm) $(dir_time) $(dir_tree) $(dir_simulator) $(dir_notifikasi) $(dir_point) $(dir_prioqueue)

adt_stack:
	$(CC) $(dir_ns)main_stack.exe $(dir)stack/main_stack.c $(dir_stack) $(dir_simulator) $(dir_notifikasi) $(dir_time) $(dir_wordflm) $(dir_charflm) $(dir_wordm) $(dir_charm) $(dir_point) $(dir_prioqueue)

adt_tree:
	$(CC) $(dir_ns)main_tree.exe $(dir)tree/main_tree.c $(dir_tree) $(dir_makanan) $(dir_wordflm) $(dir_charflm) $(dir_time) $(dir_wordm) $(dir_charm)

adt_wordfilemachine:
	$(CC) $(dir_ns)main_wordfilemachine.exe $(dir)wordfilemachine/main_wordfilemachine.c $(dir_wordflm) $(dir_charflm) $(dir_tree) $(dir_matrix) $(dir_point) $(dir_makanan) $(dir_wordm) $(dir_charm) $(dir_time)

adt_wordmachine:
	$(CC) $(dir_ns)main_wordmachine.exe $(dir)wordmachine/main_wordmachine.c $(dir_wordm) $(dir_charm)