//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.serviceImpl;

import com.ascent.dao.ProjectDao;
import com.ascent.pojo.Project;
import com.ascent.service.ProjectService;
import java.util.List;

public class ProjectServiceImpl implements ProjectService {
  ProjectDao projectdao;

  public ProjectServiceImpl() {
  }

  public ProjectDao getProjectdao() {
    return this.projectdao;
  }

  public void setProjectdao(ProjectDao projectdao) {
    this.projectdao = projectdao;
  }

  public void addProject(Project project) {
    this.projectdao.addProject(project);
  }

  public void deleteProject(Project project) {
    this.projectdao.deleteProject(project);
  }

  public List<Project> findAllProject(int pagno, int maxrows) {
    List<Project> projects = this.projectdao.findAllProject(pagno, maxrows);
    return projects;
  }

  public Project findProjectById(Integer id) {
    Project project = this.projectdao.findProjectById(id);
    return project;
  }

  public int getTotalCount() {
    int count = this.projectdao.getTotalCount();
    return count;
  }

  public void updateProject(Project project) {
    this.projectdao.updateProject(project);
  }
}
