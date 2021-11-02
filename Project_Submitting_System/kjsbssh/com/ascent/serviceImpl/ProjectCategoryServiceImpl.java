//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.serviceImpl;

import com.ascent.dao.ProjectCategoryDao;
import com.ascent.pojo.ProjectCategory;
import com.ascent.service.ProjectCategoryService;
import java.util.List;

public class ProjectCategoryServiceImpl implements ProjectCategoryService {
  ProjectCategoryDao projectCategoryDao;

  public ProjectCategoryServiceImpl() {
  }

  public ProjectCategoryDao getProjectCategoryDao() {
    return this.projectCategoryDao;
  }

  public void setProjectCategoryDao(ProjectCategoryDao projectCategoryDao) {
    this.projectCategoryDao = projectCategoryDao;
  }

  public void addProjectCategory(ProjectCategory category) {
    this.projectCategoryDao.addProjectCategory(category);
  }

  public void deleteProjectCategory(ProjectCategory category) {
    this.projectCategoryDao.deleteProjectCategory(category);
  }

  public List<ProjectCategory> findAllProjectCategoryByPage(int pageno, int maxrows) {
    List<ProjectCategory> categorys = this.projectCategoryDao.findAllProjectCategoryByPage(pageno, maxrows);
    return categorys;
  }

  public ProjectCategory findProjectCategoryById(Integer id) {
    ProjectCategory category = this.projectCategoryDao.findProjectCategoryById(id);
    return category;
  }

  public int getTotalCount() {
    int count = this.projectCategoryDao.getTotalCount();
    return count;
  }

  public void updateProjectCategory(ProjectCategory category) {
    this.projectCategoryDao.updateProjectCategory(category);
  }
}
