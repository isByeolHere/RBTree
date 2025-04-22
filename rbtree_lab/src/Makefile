.PHONY: clean
CFLAGS = -Wall -g
# 실행 파일 만들기
driver: driver.o rbtree.o
	$(CC) $(CFLAGS) -o driver driver.o rbtree.o
# .o 파일 만드는 법 (의존성 자동 관리)
driver.o: driver.c rbtree.h
	$(CC) $(CFLAGS) -c driver.c
rbtree.o: rbtree.c rbtree.h
	$(CC) $(CFLAGS) -c rbtree.c
run-driver: driver
	./driver
clean:
	rm -f driver *.o