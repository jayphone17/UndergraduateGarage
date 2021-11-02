//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.dao;

import com.ascent.pojo.Project;
import java.util.List;

public interface ProjectDao {
  void addProject(Project var1);

  void deleteProject(Project var1);

  void updateProject(Project var1);

  Project findProjectById(Integer var1);

  List<Project> findAllProject(int var1, int var2);

  int getTotalCount();
}
