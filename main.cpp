#include <rose.h>
#include <stp_schema.h>

void main(int argc,char **argv)
{
    stplib_init();

	RoseDesign * d = ROSE.findDesign("io1-md-214.stp.stp");

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