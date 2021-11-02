//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.dao;

import com.ascent.pojo.Expert;
import java.util.List;

public interface ExpertDao {
  void addExpert(Expert var1);

  void deleteExpert(Expert var1);

  void updateExpert(Expert var1);

  Expert findExpertById(Integer var1);

  List<Expert> findAllExpert(int var1, int var2);

  int getTotalCount();
}
