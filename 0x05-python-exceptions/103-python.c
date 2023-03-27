#include <python.h>

void print_python_list(pyObject *p);
void print_python_bytes(pyObject *p);
void print_python_float(pyObject *p);

/**
 * print_python_list - prints basic info about python lists
 * @p: A pyobject list object
 */
void print_python_list(pyObject *p)
{
	py_ssize_t size, alloc, i;
	const char *type;
	pyListObject *list = (pyListObject *)p;
	pyVarObject *var = (pyvarObject *)p;

	size = var->ob_size;
	alloc = list->allocated;

	fflush(stdout);

	printf("[*] python list info\n");
	if (strcmp(P->ob_type->tp_name, "list") != 0)
	{
		printf("  [ERROR] Invalid list object\n");
		return;
	}

	printf("[*] Size of the python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", alloc);

	for (i = 0; i < size; i++)
	{
		type = list->ob_type->tp_name;
		printf("Element %ld: %s\n", i, type);
		if (strcmp(type, "bytes") == 0)
			print_python_bytes(list->ob_item[i]);
		else if (strcmp(type, "float") == 0)
			print_python_float(list->ob_item[i]);
	}
}

/**
 * print_python_bytes - prints basic info about python bytes objects
 * @p: A pyobject byte object
 */
void print_python_bytes(pyObject *p)
{
	py_ssize_t size, i;
	pyBytesObject *bytes = (pyBytesObject *)p;

	fflush(stdout);

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes") != 0)
	{
		printf("  [ERROR] Invalid bytes object\n");
		return;
	}

	printf("  size: %ld\n", ((pyVarObject *)p)->ob_size);
	printf("  trying string: %s\n", bytes->ob_sval);

	if (((pyVarObject *)p)->ob_size >= 10)
		size = 10;
	else
		size = ((pyVarObject *)p)->ob_size + 1;

	printf("  first %ld bytes: ", size);
	for (i = 0; i < size; i++)
	{
		printf("%02hhx", bytes->ob_sval[i]);
		if (i == (size - 1))
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_python_float - prints basic info about python float objects
 * @p: A pyobject float object
 */
void print_python_float(pyObject *p)
{
	char *buffer = NULL;

	pyFloatObject *float_obj = (pyFloatObject *)p;

	fflush(stdout);

	printf("[.] float object info\n");
	if (strcmp(p->ob_type->tp_name, "float") != 0)
	{
		printf("  [ERROR] Invalid float object\n");
		return;
	}

	buffer = pyos_double_to_string(float_obj->ob_fval, 'r', 0,
			py_DISF_ADD_DOT_0, NULL);
	printf("  value: %s\n", buffer);
	pyMem_Free(buffer);
}
