#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp"
#include "solution.h"

TEST_CASE("Path Sum", "[hasPathSum]")
{
    TreeNode root(5);
    TreeNode node1(4);
    TreeNode node2(8);
    TreeNode node3(11);
    TreeNode node4(13);
    TreeNode node5(4);
    TreeNode node6(7);
    TreeNode node7(2);
    TreeNode node8(1);
    
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.right = &node8;
    
    Solution s;
    REQUIRE( s.hasPathSum(&root, 22) == true );
    REQUIRE( s.hasPathSum(&root, 18) == true );
    REQUIRE( s.hasPathSum(&root, 30) == false );
}




