//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.action;

import com.ascent.pojo.Project;
import com.ascent.service.ProjectService;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;

public class ProjectAction extends ActionSupport {
  Project project;
  ProjectService projectService;

  public ProjectAction() {
  }

  public Project getProject() {
    return this.project;
  }

  public void setProject(Project project) {
    this.project = project;
  }

  public ProjectService getProjectService() {
    return this.projectService;
  }

  public void setProjectService(ProjectService projectService) {
    this.projectService = projectService;
  }

  public String findProjectBypage() {
    HttpServletRequest request = ServletActionContext.getRequest();
    boolean var2 = true;

    int pageno;
    try {
      pageno = request.getParameter("pageno") == null ? 1 : Integer.parseInt(request.getParameter("pageno"));
    } catch (NumberFormatException var8) {
      pageno = 1;
    }

    List<Project> projects = this.projectService.findAllProject(pageno, 3);
    ActionContext context = ActionContext.getContext();
    System.out.println(">>" + this.projectService.getTotalCount());
    int size = this.projectService.getTotalCount();
    if (size < 3) {
      size = 1;
    } else if (size % 3 != 0) {
      size = size / 3 + 1;
    } else {
      size /= 3;
    }

    int[] count = new int[size];

    for(int i = 0; i < size; ++i) {
      count[i] = i + 1;
    }

    context.put("total", count);
    context.put("projects", projects);
    return "success";
  }
}
