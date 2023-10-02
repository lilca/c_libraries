# Makefile

# Macro
PD_NAME = tagDataControllerWriter
OBJ_LIST = tag_data_controller_writer.o tag_data_controller.o
GCC_OPTION = -Wall

#
debug: $(OBJ_LIST)
	gcc $(GCC_OPTION) $(OBJ_LIST) -o $(PD_NAME)
tag_data_controller_writer.o: tag_data_controller_writer.c tag_data_controller_writer.h
	gcc $(GCC_OPTION) -c tag_data_controller_writer.c
tag_data_controller.o: tag_data_controller.c tag_data_controller.h
	gcc $(GCC_OPTION) -c tag_data_controller.c
