#pragma once

#include "parametervirtualwidget.h"
#include "ui_parametervector.h"

class ParameterVector : public ParameterVirtualWidget, Ui::ParameterVector
{
	Q_OBJECT

public:
	ParameterVector(QWidget *parent, VectorParameter *parameter, DescriptionStyle descriptionStyle);
	void setValue() override;
	void valueApplied() override;

protected slots:
	void onChanged();
	void onEditingFinished();

private:
	VectorParameter* parameter;
	std::vector<QDoubleSpinBox*> spinboxes;
	std::vector<double> lastSent;
	std::vector<double> lastApplied;
};
