import { useState, useEffect, useCallback } from 'react';

function useKnapsack(issues, tempoTotal) {
  const [selecionadas, setSelecionadas] = useState([]);

  const knapsack = useCallback(() => {
    if (!issues || issues.length === 0 || !tempoTotal) {
      setSelecionadas([]);
      return;
    };
    let issuesOrdenadas = [...issues];

    issuesOrdenadas.sort((a, b) => {
      const pesoA = parseInt(a.dificuldade, 10) / parseInt(a.tempo, 10);
      const pesoB = parseInt(b.dificuldade, 10) / parseInt(b.tempo, 10);

      if (pesoA > pesoB) {
        return -1;
      } else if (pesoA < pesoB) {
        return 1;
      }

      return 0;
    });

    let parsedTempoTotal = parseInt(tempoTotal, 10);
    let copyArr = [];

    for (let i = 0; i < issuesOrdenadas.length; i++) {
      issuesOrdenadas[i].tempo = parseInt(issuesOrdenadas[i].tempo, 10);

      if (parsedTempoTotal === 0) {
        setSelecionadas(copyArr);
        break;
      } else if (issuesOrdenadas[i].tempo <= parsedTempoTotal) {
        copyArr.push({ ...issuesOrdenadas[i], porcentagem: 1 });
        parsedTempoTotal -= parseInt(issuesOrdenadas[i].tempo, 10);
      } else if (parsedTempoTotal > 0) {
        let val = parseInt(parsedTempoTotal, 10) / parseInt(issuesOrdenadas[i].tempo, 10);
        copyArr.push({ ...issuesOrdenadas[i], porcentagem: val });
        parsedTempoTotal = 0;
      }
    }

    setSelecionadas(copyArr);
  }, [issues, tempoTotal]);

  useEffect(() => {
    knapsack();
  }, [issues, tempoTotal, knapsack]);

  return selecionadas;
}

export default useKnapsack;
