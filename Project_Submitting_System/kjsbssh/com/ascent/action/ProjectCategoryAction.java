//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.action;

import com.ascent.pojo.ProjectCategory;
import com.ascent.service.ProjectCategoryService;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;

public class ProjectCategoryAction extends ActionSupport {
  ProjectCategory projectCategory;
  ProjectCategoryService categoryService;

  public ProjectCategoryAction() {
  }

  public ProjectCategory getProjectCategory() {
    return this.projectCategory;
  }

  public void setProjectCategory(ProjectCategory projectCategory) {
    this.projectCategory = projectCategory;
  }

  public ProjectCategoryService getCategoryService() {
    return this.categoryService;
  }

  public void setCategoryService(ProjectCategoryService categoryService) {
    this.categoryService = categoryService;
  }

  public String findAllProjectCategorys() {
    HttpServletRequest request = ServletActionContext.getRequest();
    boolean var2 = true;

    int pageno;
    try {
      pageno = request.getParameter("pageno") == null ? 1 : Integer.parseInt(request.getParameter("pageno"));
    } catch (NumberFormatException var8) {
      pageno = 1;
    }

    List<ProjectCategory> categorys = this.categoryService.findAllProjectCategoryByPage(pageno, 3);
    ActionContext context = ActionContext.getContext();
    System.out.println(">>" + this.categoryService.getTotalCount());
    int size = this.categoryService.getTotalCount();
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
    context.put("categorys", categorys);
    return "success";
  }

  public String displayUpdateCategory() {
    HttpServletRequest request = ServletActionContext.getRequest();
    ActionContext context = ActionContext.getContext();
    String id = request.getParameter("id");
    int categoryid = Integer.parseInt(id);
    ProjectCategory category = this.categoryService.findProjectCategoryById(categoryid);
    context.put("category", category);
    return "success";
  }

  public String updateCategory() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int categoryid = Integer.parseInt(id);
    ProjectCategory category = this.categoryService.findProjectCategoryById(categoryid);
    category.setCategoryname(this.projectCategory.getCategoryname());
    this.categoryService.updateProjectCategory(category);
    return "success";
  }

  public String addCategory() {
    try {
      this.categoryService.addProjectCategory(this.projectCategory);
    } catch (Exception var2) {
      var2.printStackTrace();
      return "error";
    }

    System.out.println("ddddddddddddddddddddd");
    return "success";
  }

  public String deleteCategory() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int categoryid = Integer.parseInt(id);
    ProjectCategory category = this.categoryService.findProjectCategoryById(categoryid);
    this.categoryService.deleteProjectCategory(category);
    return "success";
  }
}
