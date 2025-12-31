/**
 * Windows serial library tests.
 * These tests verify that the library compiles and basic API works on Windows.
 */

#include "gtest/gtest.h"
#include "serial/serial.h"

#include <string>
#include <vector>

using namespace serial;

namespace
{

    // Basic API sanity tests (no hardware required)

    TEST(SerialAPITests, DefaultConstruction)
    {
        Serial port;
        EXPECT_FALSE(port.isOpen());
        EXPECT_EQ(port.getPort(), "");
    }

    TEST(SerialAPITests, ListPorts)
    {
        // Should not throw; may return empty list if no ports available
        std::vector<PortInfo> ports = list_ports();
        // Just ensure the call succeeded
        SUCCEED();
    }

    TEST(SerialAPITests, TimeoutConstruction)
    {
        Timeout t = Timeout::simpleTimeout(1000);
        EXPECT_EQ(t.read_timeout_constant, 1000u);
    }

    TEST(SerialAPITests, OpenNonExistentPort)
    {
        Serial port;
        // Attempting to open a bogus port should throw
        EXPECT_THROW(port.open(), std::exception);
    }

    TEST(SerialAPITests, SetPortBeforeOpen)
    {
        Serial port;
        port.setPort("COM999");
        EXPECT_EQ(port.getPort(), "COM999");
        EXPECT_FALSE(port.isOpen());
    }

} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
