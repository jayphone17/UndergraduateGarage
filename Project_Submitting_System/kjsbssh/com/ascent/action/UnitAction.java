//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.action;

import com.ascent.pojo.Project;
import com.ascent.pojo.ProjectCategory;
import com.ascent.pojo.Unit;
import com.ascent.service.ProjectCategoryService;
import com.ascent.service.ProjectService;
import com.ascent.service.UnitService;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import java.util.List;
import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;

public class UnitAction extends ActionSupport {
  Project project;
  ProjectService projectService;
  Unit unit;
  UnitService unitService;
  ProjectCategoryService projectCategory;

  public UnitAction() {
  }

  public Project getProject() {
    return this.project;
  }

  public void setProject(Project project) {
    this.project = project;
  }

  public Unit getUnit() {
    return this.unit;
  }

  public void setUnit(Unit unit) {
    this.unit = unit;
  }

  public UnitService getUnitService() {
    return this.unitService;
  }

  public void setUnitService(UnitService unitService) {
    this.unitService = unitService;
  }

  public ProjectCategoryService getProjectCategory() {
    return this.projectCategory;
  }

  public void setProjectCategory(ProjectCategoryService projectCategory) {
    this.projectCategory = projectCategory;
  }

  public String displayUpdateUnit() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int unitid = Integer.parseInt(id);
    Unit u = this.unitService.findUnitById(unitid);
    ActionContext context = ActionContext.getContext();
    context.put("unit", u);
    return "success";
  }

  public String updateUint() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int unitid = Integer.parseInt(id);
    Unit u = this.unitService.findUnitById(unitid);
    u.setUnitname(this.unit.getUnitname());
    u.setAddress(this.unit.getAddress());
    u.setCorporation(this.unit.getCorporation());
    u.setInvestment(this.unit.getInvestment());
    u.setType(this.unit.getType());
    u.setTel(this.unit.getTel());
    u.setEmail(this.unit.getEmail());
    u.setFax(this.unit.getFax());
    u.setZipcode(this.unit.getZipcode());
    u.setIntroduction(this.unit.getIntroduction());
    this.unitService.updateUnit(u);
    return "success";
  }

  public String deleteUnit() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int unitid = Integer.parseInt(id);
    Unit u = this.unitService.findUnitById(unitid);
    this.unitService.deleteUnit(u);
    return "success";
  }

  public String unitInformation() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int unitid = Integer.parseInt(id);
    Unit unit = this.unitService.findUnitById(unitid);
    ActionContext context = ActionContext.getContext();
    context.put("unit", unit);
    System.out.println("unitInfomation执行完毕!");
    return "success";
  }

  public String updateUnitInfo() {
    System.out.println("进入了updateUnitInfo方法!");
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int unitid = Integer.parseInt(id);
    Unit unt = this.unitService.findUnitById(unitid);
    unt.setUnitname(this.unit.getUnitname());
    unt.setAddress(this.unit.getAddress());
    unt.setCorporation(this.unit.getCorporation());
    unt.setInvestment(this.unit.getInvestment());
    unt.setType(this.unit.getType());
    unt.setTel(this.unit.getTel());
    unt.setEmail(this.unit.getEmail());
    unt.setFax(this.unit.getFax());
    unt.setZipcode(this.unit.getZipcode());
    unt.setIntroduction(this.unit.getIntroduction());
    this.unitService.updateUnit(unt);
    return "success";
  }

  public String updatePassword() {
    System.out.println("进入了updatePassword方法!");
    HttpServletRequest request = ServletActionContext.getRequest();
    String oldpassword = request.getParameter("oldpassword");
    String newpassword = request.getParameter("newpassword");
    String repeatpassword = request.getParameter("repeatpassword");
    String id = request.getParameter("id");
    int unitid = Integer.parseInt(id);
    Unit unt = this.unitService.findUnitById(unitid);
    System.out.println("unt对象出始化成功");
    System.out.println(unt.getUser().getPassword());
    if (unt.getUser().getPassword().equals(oldpassword)) {
      System.out.println("进入方法判断1");
      if (newpassword.equals(repeatpassword)) {
        System.out.println("进入方法判断2");
        unt.getUser().setPassword(newpassword);
        this.unitService.updateUnit(unt);
        return "success";
      }
    }

    return "error";
  }

  public String findAllProjectCategory() {
    HttpServletRequest request = ServletActionContext.getRequest();
    boolean var2 = true;

    int pageno;
    try {
      pageno = request.getParameter("pageno") == null ? 1 : Integer.parseInt(request.getParameter("pageno"));
    } catch (NumberFormatException var8) {
      pageno = 1;
    }

    List<ProjectCategory> categorys = this.projectCategory.findAllProjectCategoryByPage(pageno, 3);
    ActionContext context = ActionContext.getContext();
    System.out.println(">>" + this.projectCategory.getTotalCount());
    int size = this.projectCategory.getTotalCount();
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
    System.out.println("findAllProjectCategory()运行完毕!");
    return "success";
  }

  public String displayProjectCategory() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int categoryid = Integer.parseInt(id);
    ProjectCategory category = this.projectCategory.findProjectCategoryById(categoryid);
    ActionContext context = ActionContext.getContext();
    context.put("category", category);
    System.out.println("displayProjectCategory()运行完毕!");
    return "success";
  }

  public String addApplyProject() {
    System.out.println("进入了方法addApplyProject!");
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int unitid = Integer.parseInt(id);
    Unit unt = this.unitService.findUnitById(unitid);
    this.project.setUnit(unt);
    this.projectService.addProject(this.project);
    System.out.println("addApplyProject执行完毕!");
    return "success";
  }

  public ProjectService getProjectService() {
    return this.projectService;
  }

  public void setProjectService(ProjectService projectService) {
    this.projectService = projectService;
  }
}
