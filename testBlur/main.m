
status = system('./execute_blurTests.sh 1 1 100'); % generate the file text with data


file = fopen("data_blurTests.txt","r");
formatSpec = '%d %f %f %d';
data = textscan(file, formatSpec);
fclose(file);

nPixelsArray = double(data{1});
timeArray = double(data{2}); % 1
caltimeArray = double(data{3});
PIXMEMArray = double(data{4}); % 2

%% Logaritmo do tempo de execucao em funcao do logaritmo de n
f1_time = figure(1);

% Version 1
plot(log(nPixelsArray(1:2:end)),log(timeArray(1:2:end)),'or-');
hold on;
% Version 2
plot(log(nPixelsArray(2:2:end)),log(timeArray(2:2:end)),'ob-');

grid on
title("Logaritmo do tempo de execucao em funcao do logaritmo de n pixeis")
legend("Versao 1","Versao 2")
xlabel("Logaritmo do numero de pixeis da imagem")
ylabel("Logaritmo do tempo de execucao (log(segundos))")

if 1
  f1_time.PaperType='A4';
  f1_time.PaperOrientation='landscape';
  f1_time.PaperUnits='points';
  print('time/log_time_100x100.pdf','-dpdf','-noui','-fillpage');
end

%% Tempo de execucao em funcao de n
f2_time = figure(2);

%Version 1
plot(nPixelsArray(1:2:end),timeArray(1:2:end),'or-');
hold on;
% Version 2
plot(nPixelsArray(2:2:end),timeArray(2:2:end),'ob-');

grid on
title("Tempo de execucao em funcao de n pixeis")
legend("Versao 1","Versao 2")
xlabel("Numero de pixeis da imagem")
ylabel("Tempo de execucao (segundos)")

if 1
  f2_time.PaperType='A4';
  f2_time.PaperOrientation='landscape';
  f2_time.PaperUnits='points';
  print('time/time_100x100.pdf','-dpdf','-noui','-fillpage');
end


%% Logaritmo do numero de acessos (log(PIXMEM)) em funcao do logaritmo de n pixeis
f3_pixmem = figure(3);

%Version 1
plot(log(nPixelsArray(1:2:end)),log(PIXMEMArray(1:2:end)),'or-');
hold on;
% Version 2
plot(log(nPixelsArray(2:2:end)),log(PIXMEMArray(2:2:end)),'ob-');

grid on
title("Logaritmo do numero de acessos (log(PIXMEM)) em funcao do logaritmo de n pixeis")
legend("Versao 1","Versao 2")
xlabel("Logaritmo do numero de pixeis da imagem")
ylabel("Logaritmo do numero de acessos (log(PIXMEM))")

if 1
  f3_pixmem.PaperType='A4';
  f3_pixmem.PaperOrientation='landscape';
  f3_pixmem.PaperUnits='points';
  print('pixmem/log_pixmem_100x100.pdf','-dpdf','-noui','-fillpage');
end

%% Numero de acessos (PIXMEM) em funcao de n
f3_pixmem = figure(3);

%Version 1
plot(nPixelsArray(1:2:end),PIXMEMArray(1:2:end),'or-');
hold on;
% Version 2
plot(nPixelsArray(2:2:end),PIXMEMArray(2:2:end),'ob-');

grid on
title("Numero de acessos (PIXMEM) em funcao de n pixeis")
legend("Versao 1","Versao 2")
xlabel("Numero de pixeis da imagem")
ylabel("Numero de acessos (PIXMEM)")

if 1
  f3_pixmem.PaperType='A4';
  f3_pixmem.PaperOrientation='landscape';
  f3_pixmem.PaperUnits='points';
  print('pixmem/onlyV2_pixmem_100x100.pdf','-dpdf','-noui','-fillpage');
end
