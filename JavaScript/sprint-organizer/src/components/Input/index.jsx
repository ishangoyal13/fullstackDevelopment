import * as S from './styles';

function Input({ label, register, error, ...props }) {
  return (
    <S.InputWrapper>
      <S.InputGroup>
        <S.Input {...register} id={register.name} {...props} />
        <S.Label htmlFor={register.name}>
          {label}
        </S.Label>
      </S.InputGroup>
      {error && <span>{error?.message}</span>}
    </S.InputWrapper>
  );
}

export default Input;
