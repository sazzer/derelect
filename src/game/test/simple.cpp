#include <bandit/bandit.h>
using namespace bandit;

go_bandit([](){
  describe("a thing", [&](){
    it("should do something", [&](){
      AssertThat(!false, IsTrue());
    });
  });
});
