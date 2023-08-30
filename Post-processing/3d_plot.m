a1 = dlmread('');
a2 = dlmread('');
a3 = dlmread('');
x1 = a1(:,3)*-1;
y1 = a1(:,5)*-1;
z1 = a1(:,4);
c1 = 4;
z1 = (z1-c1);
x2 = a2(:,3)*-1;
y2 = a2(:,5)*-1;
z2 = a2(:,4);
z2 = (z2-c1);
x3 = a3(:,3);
y3 = a3(:,5);
z3 = a3(:,4);
z3 = z3-c1;
hold on;
plot3(x1,y1,z1,'red', 'DisplayName', 'Double walls', 'linewidth',4);
plot3(x2,y2,z2,'blue', 'DisplayName', 'Single wall','linewidth',4);
plot3(x3,y3,z3,'color',[0 0.5 0], 'DisplayName', 'No wall','linewidth',4);
grid on;
ylim([-0.3 2.1]);
xlim([-0.3 2.1]);
zlim([0 50]);
xticks([0 0.5 1 1.5 2]);
yticks([0 0.5 1 1.5 2]);
zticks([0 10 20 30 40 50]);
xlabel '\itx';
ylabel '\itz';
zlabel '\ity';
set(findall(gcf,'-property','FontSize'),'FontSize',25);
set(gca,'YDir','reverse');
pbaspect([0.6 0.6 1]);
legend show;
