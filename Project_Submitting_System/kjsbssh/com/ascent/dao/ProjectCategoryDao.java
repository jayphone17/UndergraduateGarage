//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.dao;

import com.ascent.pojo.ProjectCategory;
import java.util.List;

public interface ProjectCategoryDao {
  void addProjectCategory(ProjectCategory var1);

  void deleteProjectCategory(ProjectCategory var1);

  void updateProjectCategory(ProjectCategory var1);

  ProjectCategory findProjectCategoryById(Integer var1);

  List<ProjectCategory> findAllProjectCategoryByPage(int var1, int var2);

  int getTotalCount();
}
