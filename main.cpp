#include <rose.h>
#include <stp_schema.h>

void main(int argc,char * argv[])
{
    stplib_init();

	if (argc != 2){ //Makes sure that command line has 2 arguments
		printf("Usage: %s step file\n", argv[0]);
		return;
	}

	RoseDesign * d = ROSE.findDesign(argv[1]);

	if (!d) return;

	RoseCursor cur;
	RoseObject * obj;

	cur.traverse(d);
	cur.domain(ROSE_DOMAIN(stp_product_definition));

	while ((obj = cur.next()) != 0){
		stp_product_definition * pd = ROSE_CAST(stp_product_definition, obj);

		printf("Product Definiton ID #%d \n", pd->id());
	}

	system("pause");

    return;
}