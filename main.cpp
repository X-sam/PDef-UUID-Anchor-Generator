// $RCSfile: $
// $Revision: $ $Date: $
// Auth: Samson Bonfante (bonfante@steptools.com)
// 
// Copyright (c) 1991-2015 by STEP Tools Inc. 
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rose.h>
#include <stp_schema.h>
#include "GUID.h"
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
		unsigned char GUID[16];
		get_guid(GUID);
		printf("Product Definiton ID #%d \t GUID: %s\n", pd->id(),GUID);
	}


    return;
}