/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    PhysicalNumber x(1, Unit::CM);
    PhysicalNumber y(2, Unit::SEC);
    PhysicalNumber z(400, Unit::TON);
    PhysicalNumber t(100, Unit::G);
    PhysicalNumber w(500, Unit::SEC);
    PhysicalNumber f(10, Unit::KM);
    PhysicalNumber s(1400, Unit::M);
    PhysicalNumber e(999 , Unit::G);
    PhysicalNumber o(250 , Unit::G);
    PhysicalNumber r(2.5 , Unit::TON);
    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
      .setname("our tests")
      .CHECK_OUTPUT(x, "1[cm]")
      .CHECK_OUTPUT(y, "2[sec]")
      .CHECK_OUTPUT(z, "400[ton]")
      .CHECK_OUTPUT(t, "100[g]")
      .CHECK_OUTPUT(w, "500[sec]")
      .CHECK_THROWS(x+y)
      .CHECK_THROWS(x+z)
      .CHECK_THROWS(x+t)
      .CHECK_THROWS(x+w)
      .CHECK_THROWS(y+x)
      .CHECK_THROWS(y+z)
      .CHECK_THROWS(y+t)
      .CHECK_THROWS(z+x)
      .CHECK_THROWS(z+y)
      .CHECK_THROWS(z+w)
      .CHECK_THROWS(t+x)
      .CHECK_THROWS(t+y)
      .CHECK_THROWS(t+w)
      .CHECK_THROWS(w+x)
      .CHECK_THROWS(w+z)
      .CHECK_THROWS(w+t)
      .CHECK_OUTPUT(x + x, "2[cm]")
      .CHECK_OUTPUT(y + y, "4[sec]")
      .CHECK_OUTPUT(z + z, "800[ton]")
      .CHECK_OUTPUT(t + t, "200[g]")
      .CHECK_OUTPUT(w + w, "1000[sec]")
      .CHECK_OUTPUT(y + w, "502[sec]")
      .CHECK_OUTPUT(w + y, "502[sec]")
      .CHECK_OUTPUT(y + d, "1802[sec]")
      .CHECK_OUTPUT(w + d, "2300[sec]")
      .CHECK_EQUAL(z > t, true)
      .CHECK_OUTPUT(f, "10[km]")
      .CHECK_OUTPUT(s, "1400[m]")
      .CHECK_OUTPUT((f+=s), "11.4[km]")
      .CHECK_OUTPUT(f, "11.4[km]")
      .CHECK_OUTPUT(f--, "11.4[km]")
      .CHECK_OUTPUT(f, "10.4[km]")
      .CHECK_OUTPUT(f++, "10.4[km]")
      .CHECK_OUTPUT(-s, "-1400[m]")
      .CHECK_OUTPUT(s, "1400[m]")
      .CHECK_OUTPUT((f -= s), "10[km]")
      .CHECK_EQUAL(f > s, true)
      .CHECK_EQUAL(f < s, false)
      .CHECK_EQUAL(f >= s, true)
      .CHECK_EQUAL(f <= s, false)
      .CHECK_EQUAL(f == s, false)
      .CHECK_EQUAL(f != s, true)
      .CHECK_OUTPUT(++x , "2[cm]")
      .CHECK_OUTPUT(--x , "1[cm]")
      .CHECK_OUTPUT(e , "999[g]")
      .CHECK_OUTPUT(e++ , "999[g]")
      .CHECK_OUTPUT(--e , "999[g]")
      .CHECK_OK(istringstream("250[g]") >> o)
      .CHECK_OK(istringstream("2.5[ton]") >> r)
      .CHECK_EQUAL(r != o, true)
      .CHECK_EQUAL(r == o, false)
      .CHECK_EQUAL(r < o, false)
      .CHECK_EQUAL(r > o, true)
      .CHECK_EQUAL(r <= o, false)
      .CHECK_EQUAL(r >= o, true)

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
