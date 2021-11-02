//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.pojo;

import java.io.Serializable;
import java.util.Date;

public class Project implements Serializable {
  private Integer projectId;
  private Unit unit;
  private ProjectCategory projectCategory;
  private String applicant;
  private String grade;
  private String education;
  private Date fillDate;
  private String status;
  private String future;
  private String analysis;
  private String way;
  private String result;
  private String projectname;
  private String capital;
  private String expertOpinion;
  private Double score;
  private Integer ispass;
  private String temp1;
  private String attribute58;
  private String attribute59;
  private String attribute60;

  public Project() {
  }

  public Project(Unit unit, ProjectCategory projectCategory, String applicant, String grade, String education, Date fillDate, String status, String future, String analysis, String way, String result, String projectname, String capital, String expertOpinion, Double score, Integer ispass, String temp1, String attribute58, String attribute59, String attribute60) {
    this.unit = unit;
    this.projectCategory = projectCategory;
    this.applicant = applicant;
    this.grade = grade;
    this.education = education;
    this.fillDate = fillDate;
    this.status = status;
    this.future = future;
    this.analysis = analysis;
    this.way = way;
    this.result = result;
    this.projectname = projectname;
    this.capital = capital;
    this.expertOpinion = expertOpinion;
    this.score = score;
    this.ispass = ispass;
    this.temp1 = temp1;
    this.attribute58 = attribute58;
    this.attribute59 = attribute59;
    this.attribute60 = attribute60;
  }

  public Integer getProjectId() {
    return this.projectId;
  }

  public void setProjectId(Integer projectId) {
    this.projectId = projectId;
  }

  public Unit getUnit() {
    return this.unit;
  }

  public void setUnit(Unit unit) {
    this.unit = unit;
  }

  public ProjectCategory getProjectCategory() {
    return this.projectCategory;
  }

  public void setProjectCategory(ProjectCategory projectCategory) {
    this.projectCategory = projectCategory;
  }

  public String getApplicant() {
    return this.applicant;
  }

  public void setApplicant(String applicant) {
    this.applicant = applicant;
  }

  public String getGrade() {
    return this.grade;
  }

  public void setGrade(String grade) {
    this.grade = grade;
  }

  public String getEducation() {
    return this.education;
  }

  public void setEducation(String education) {
    this.education = education;
  }

  public Date getFillDate() {
    return this.fillDate;
  }

  public void setFillDate(Date fillDate) {
    this.fillDate = fillDate;
  }

  public String getStatus() {
    return this.status;
  }

  public void setStatus(String status) {
    this.status = status;
  }

  public String getFuture() {
    return this.future;
  }

  public void setFuture(String future) {
    this.future = future;
  }

  public String getAnalysis() {
    return this.analysis;
  }

  public void setAnalysis(String analysis) {
    this.analysis = analysis;
  }

  public String getWay() {
    return this.way;
  }

  public void setWay(String way) {
    this.way = way;
  }

  public String getResult() {
    return this.result;
  }

  public void setResult(String result) {
    this.result = result;
  }

  public String getProjectname() {
    return this.projectname;
  }

  public void setProjectname(String projectname) {
    this.projectname = projectname;
  }

  public String getCapital() {
    return this.capital;
  }

  public void setCapital(String capital) {
    this.capital = capital;
  }

  public String getExpertOpinion() {
    return this.expertOpinion;
  }

  public void setExpertOpinion(String expertOpinion) {
    this.expertOpinion = expertOpinion;
  }

  public Double getScore() {
    return this.score;
  }

  public void setScore(Double score) {
    this.score = score;
  }

  public Integer getIspass() {
    return this.ispass;
  }

  public void setIspass(Integer ispass) {
    this.ispass = ispass;
  }

  public String getTemp1() {
    return this.temp1;
  }

  public void setTemp1(String temp1) {
    this.temp1 = temp1;
  }

  public String getAttribute58() {
    return this.attribute58;
  }

  public void setAttribute58(String attribute58) {
    this.attribute58 = attribute58;
  }

  public String getAttribute59() {
    return this.attribute59;
  }

  public void setAttribute59(String attribute59) {
    this.attribute59 = attribute59;
  }

  public String getAttribute60() {
    return this.attribute60;
  }

  public void setAttribute60(String attribute60) {
    this.attribute60 = attribute60;
  }
}
