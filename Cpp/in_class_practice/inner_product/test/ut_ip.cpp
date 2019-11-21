#include <gtest/gtest.h>
double const epsilon = 0.0001;
#include "ut_ip.h"
#include "ut_sort.h"
#include "ut_shape.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
