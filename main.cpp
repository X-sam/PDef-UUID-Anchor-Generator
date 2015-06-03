#include <rose.h>
#include <stp_schema.h>
#include <iostream>

using namespace std;

void main(int argc,char * argv[])
{
    stplib_init();

	if (argc != 2){ //Makes sure that command line has 2 arguments
		cerr << "Usage: " << argv[0] << "step file\n";
		exit(1);
	}

	RoseDesign * d = ROSE.findDesign(argv[1]);

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