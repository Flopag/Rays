#include <gtest/gtest.h>
#include <stdexcept>

#include "screen/screen.hpp"

using namespace screen;
using namespace std;

TEST(instanciation, BasicIntances) {
    EXPECT_EQ(Screen(1, 1).to_string(), "□ \n");
    EXPECT_EQ(Screen(2, 1).to_string(), "□ □ \n");
    EXPECT_EQ(Screen(1, 2).to_string(), "□ \n□ \n");
    EXPECT_EQ(Screen(2, 2).to_string(), "□ □ \n□ □ \n");
}

TEST(instanciation, UnusualIntances) {
    EXPECT_EQ(Screen(0, 0).to_string(), "");
    EXPECT_EQ(Screen(1, 0).to_string(), "");
    EXPECT_EQ(Screen(0, 1).to_string(), "");
}

TEST(instanciation, ForbiddenIntances) {
    EXPECT_THROW(Screen(-1, 1), runtime_error);
    EXPECT_THROW(Screen(1, -1), runtime_error);
    EXPECT_THROW(Screen(-1, -1), runtime_error);
}

namespace test {
    
    class Screen_Test : public testing::Test {
        protected:
            Screen screen = Screen(2, 2);
    };

    TEST_F(Screen_Test, Usual_set_pixel_then_flush){
        EXPECT_EQ(screen.set_pixel(0, 0, true).to_string(), "■ □ \n□ □ \n");
        EXPECT_EQ(screen.set_pixel(0, 0, true).to_string(), "■ □ \n□ □ \n");
        EXPECT_EQ(screen.set_pixel(0, 0, false).to_string(), "□ □ \n□ □ \n");
        EXPECT_EQ(screen.set_pixel(0, 0, false).to_string(), "□ □ \n□ □ \n");
        EXPECT_EQ(screen.set_pixel(0, 0, true).to_string(), "■ □ \n□ □ \n");
        EXPECT_EQ(screen.set_pixel(1, 1, true).to_string(), "■ □ \n□ ■ \n");
        EXPECT_EQ(screen.set_pixel(1, 0, true).to_string(), "■ ■ \n□ ■ \n");
        EXPECT_EQ(screen.set_pixel(0, 1, true).to_string(), "■ ■ \n■ ■ \n");
        EXPECT_EQ(screen.flush().to_string(), "□ □ \n□ □ \n");
    }

    TEST_F(Screen_Test, forbidden_set_pixel){
        for(bool i=true; i; i=false){
            EXPECT_EQ(screen.set_pixel(-1, 0, i).to_string(), "□ □ \n□ □ \n");
            EXPECT_EQ(screen.set_pixel(-1, -1, i).to_string(), "□ □ \n□ □ \n");
            EXPECT_EQ(screen.set_pixel(0, -1, i).to_string(), "□ □ \n□ □ \n");
    
            EXPECT_EQ(screen.set_pixel(2, 0, i).to_string(), "□ □ \n□ □ \n");
            EXPECT_EQ(screen.set_pixel(2, 2, i).to_string(), "□ □ \n□ □ \n");
            EXPECT_EQ(screen.set_pixel(0, 2, i).to_string(), "□ □ \n□ □ \n");
    
            EXPECT_EQ(screen.set_pixel(3, 0, i).to_string(), "□ □ \n□ □ \n");
            EXPECT_EQ(screen.set_pixel(3, 3, i).to_string(), "□ □ \n□ □ \n");
            EXPECT_EQ(screen.set_pixel(0, 3, i).to_string(), "□ □ \n□ □ \n");
        }
    }
} // namespace test